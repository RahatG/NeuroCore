# __init__.py
from .endpoints import router as endpoints_router
from .auth import router as auth_router
from .health_check import router as health_check_router

__all__ = ["endpoints_router", "auth_router", "health_check_router"]
