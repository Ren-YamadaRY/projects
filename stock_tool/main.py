from src.fetch import get_stock
from src.analysis import add_ma, trend, detect_cross_all
from src.plot import plot

code = input("銘柄コード： ")
if not code.endswith(".T"):
    code += ".T"
chart_type = input("candle / line： ")
chart_type = chart_type.lower()
df = get_stock(code)
df = add_ma(df)

print(detect_cross_all(df))
print(trend(df))

plot(df, chart_type)
