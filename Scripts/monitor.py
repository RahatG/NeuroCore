import time
from ..src.utils.logger import get_logger

def monitor():
    logger = get_logger("Monitor")
    while True:
        logger.log("System is running.")
        time.sleep(60)

if __name__ == "__main__":
    monitor()
