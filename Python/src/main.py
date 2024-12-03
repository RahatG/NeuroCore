from fastapi import FastAPI, Depends, HTTPException
from pydantic import BaseModel
from typing import List
import InterfaceEngine  # C++ module import
from .auth import router as auth_router
from .endpoints import router as endpoints_router
from .health_check import router as health_check_router
from .config.settings import settings

app = FastAPI(title="NeuroCore AI API")

# Include Routers
app.include_router(auth_router, prefix="/api/v1")
app.include_router(endpoints_router, prefix="/api/v1")
app.include_router(health_check_router, prefix="/api/v1")

# Initialize InterfaceEngine (Singleton Pattern)
try:
    engine = InterfaceEngine.InterfaceEngine(settings.data_path, settings.model_output_path)
    print("InterfaceEngine initialized successfully.")
except Exception as e:
    print(f"Failed to initialize InterfaceEngine: {e}")
    raise e

# Define Pydantic Models
class PredictRequest(BaseModel):
    text: str

class PredictResponse(BaseModel):
    prediction: List[float]

class TrainRequest(BaseModel):
    epochs: int

class TrainResponse(BaseModel):
    message: str

# Prediction Endpoint
@app.post("/api/v1/predict", response_model=PredictResponse)
def predict(request: PredictRequest):
    try:
        prediction = engine.predict(request.text)
        return PredictResponse(prediction=prediction)
    except Exception as e:
        raise HTTPException(status_code=500, detail=str(e))

# Training Endpoint
@app.post("/api/v1/train", response_model=TrainResponse)
def train(request: TrainRequest):
    try:
        engine.train(request.epochs)
        return TrainResponse(message=f"Training started for {request.epochs} epoch(s).")
    except Exception as e:
        raise HTTPException(status_code=500, detail=str(e))
