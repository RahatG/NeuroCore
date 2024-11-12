from fastapi import FastAPI
from .api import endpoints, auth, health_check
from .config.constants import API_V1_STR

app = FastAPI(title="NeuroCore AI API")

app.include_router(auth.router, prefix="/api/v1")
app.include_router(endpoints.router, prefix="/api/v1")
app.include_router(health_check.router, prefix="/api/v1")
