from fastapi import APIRouter, HTTPException
from pydantic import BaseModel
import jwt
import datetime
from ..config.settings import settings  # Ensure correct import path

router = APIRouter()

class Token(BaseModel):
    access_token: str
    token_type: str

class Login(BaseModel):
    username: str
    password: str

@router.post("/login", response_model=Token)
def login(login: Login):
    # Replace with actual user authentication logic
    if login.username == "admin" and login.password == "password":
        token = jwt.encode({
            "sub": login.username,
            "exp": datetime.datetime.utcnow() + datetime.timedelta(hours=2)
        }, settings.secret_key, algorithm=settings.algorithm)
        return {"access_token": token, "token_type": "bearer"}
    raise HTTPException(status_code=400, detail="Invalid credentials")
