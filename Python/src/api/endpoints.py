from fastapi import APIRouter, Depends
from pydantic import BaseModel
from typing import List
from ..services.inference_service import InferenceService
from ..services.training_service import TrainingService
from ..services.nlp_service import NLPService

router = APIRouter()

class PredictRequest(BaseModel):
    text: str

class PredictResponse(BaseModel):
    prediction: List[float]

class TrainRequest(BaseModel):
    epochs: int

class TrainResponse(BaseModel):
    message: str

inference_service = InferenceService()
training_service = TrainingService()
nlp_service = NLPService()

@router.post("/predict", response_model=PredictResponse)
def predict(request: PredictRequest):
    prediction = inference_service.predict(request.text)
    return PredictResponse(prediction=prediction)

@router.post("/train", response_model=TrainResponse)
def train(request: TrainRequest):
    training_service.train(request.epochs)
    return TrainResponse(message=f"Training started for {request.epochs} epochs.")
