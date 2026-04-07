import pandas as pd
import numpy as np

def add_ma(df):
    df["MA5"] = df["Close"].rolling(5).mean()
    df["MA25"] = df["Close"].rolling(25).mean()
    return df

def trend(df):
    ma5 = df["MA5"].iloc[len(df["MA5"]) - 2]
    ma25 = df["MA25"].iloc[len(df["MA25"]) - 2]
    if ma5 > ma25:
        return "上昇トレンド"
    return "下降トレンド"

def detect_cross_all(df):

    for i in range(len(df)-1, len(df)-6, -1):
        prev_ma5 = df["MA5"].iloc[i-1]
        prev_ma25 = df["MA25"].iloc[i-1]
        curr_ma5 = df["MA5"].iloc[i]
        curr_ma25 = df["MA25"].iloc[i]

        if prev_ma5 < prev_ma25 and curr_ma5 > curr_ma25:
            days_ago = len(df) - 1 - i
            return f"{days_ago}日前にゴールデンクロス"
        elif prev_ma5 > prev_ma25 and curr_ma5 < curr_ma25:
            days_ago = len(df) - 1 - i
            return f"{days_ago}日前にデッドクロス"

    return "直近5日間クロスなし"

def detect_cross_points(df):
    points = []

    for i in range(len(df)-1, len(df)-6, -1):
        prev_ma5 = df["MA5"].iloc[i-1]
        prev_ma25 = df["MA25"].iloc[i-1]
        curr_ma5 = df["MA5"].iloc[i]
        curr_ma25 = df["MA25"].iloc[i]

        if prev_ma5 < prev_ma25 and curr_ma5 > curr_ma25:
            points.append((df.index[i], df["Close"].iloc[i], "golden"))
        elif prev_ma5 > prev_ma25 and curr_ma5 < curr_ma25:
            points.append((df.index[i], df["Close"].iloc[i], "dead"))

    return points

def make_cross_series(df, points):
    golden = [np.nan] * len(df)
    dead = [np.nan] * len(df)

    for date, price, kind in points:
        idx = df.index.get_loc(date)
        if kind == "golden":
            golden[idx] = price
        else:
            dead[idx] = price

    return pd.Series(golden, index=df.index), pd.Series(dead, index=df.index)
