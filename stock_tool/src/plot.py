import matplotlib.pyplot as plt
import mplfinance as mpf
from src.analysis import detect_cross_points, make_cross_series

def plot(df, chart_type):
    points = detect_cross_points(df)
    if chart_type == "line":
        plt.clf()
        plt.plot(df["Close"], label = "Close")
        plt.plot(df["MA5"], label = "MA5")
        plt.plot(df["MA25"], label = "MA25")
        
        for date, price, kind in points:
            if kind == "golden":
                plt.scatter(
                    date,
                    price,
                    marker="^",
                    color = "green"
                )
            else:
                plt.scatter(
                    date,
                    price,
                    marker="v",
                    color = "red"
                )
        plt.xticks(df.index[::5], rotation = 45)
        plt.legend()
        plt.tight_layout()
        plt.show()
    elif chart_type == "candle":
        golden_s, dead_s = make_cross_series(df, points)
        apds = []
        if not golden_s.isna().all():
            apds.append(
                mpf.make_addplot(
                    golden_s,
                    type='scatter',
                    marker='^',
                    color = "green",
                    markersize=100
                )
            )
        if not dead_s.isna().all():
            apds.append(
                mpf.make_addplot(
                    dead_s,
                    type='scatter',
                    marker='v',
                    color = "red",
                    markersize=100
                )
            )
        mpf.plot(
            df,
            type = "candle", 
            mav = (5, 25), 
            volume = True, 
            style = "yahoo",
            addplot = apds,
            title = "Golden / Dead Cross Signals"
        )
    else:
        print("line か candleを入力してください")



