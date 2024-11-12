from fastapi import APIRouter, HTTPException
from pydantic import BaseModel
import jwt
import datetime

router = APIRouter()

SECRET_KEY = "your_secret_key"

class Token(BaseModel):
    access_token: str
    token_type: str

class Login(BaseModel):
    username: str
    password: str

@router.post("/login", response_model=Token)
def login(login: Login):
    if login.username == "admin" and login.password == "password":
        token = jwt.encode({
            "sub": login.username,
            "exp": datetime.datetime.utcnow() + datetime.timedelta(hours=2)
        }, SECRET_KEY, algorithm="HS256")
        return {"access_token": token, "token_type": "bearer"}
    raise HTTPException(status_code=400, detail="Invalid credentials")
