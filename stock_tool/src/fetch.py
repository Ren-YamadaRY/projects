import yfinance as yf

def get_stock(code):
    ticker = yf.Ticker(code)
    return ticker.history(period = "3mo")