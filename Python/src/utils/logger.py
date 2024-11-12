import logging
from ..config.settings import settings

def get_logger(name: str):
    logger = logging.getLogger(name)
    logger.setLevel(settings.log_level)
    handler = logging.StreamHandler()
    formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
    handler.setFormatter(formatter)
    logger.addHandler(handler)
    return logger
