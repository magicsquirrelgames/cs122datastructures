from pydantic import BaseModel
from fastapi import FastAPI
from fastapi.responses import JSONResponse

approved_users = {
    "user1":"password1234",
    "admin":"noneyabuisness"
}

class AuthCredentials(BaseModel):
    username:str
    password:str

app = FastAPI()
@app.post("/authenticate_user")
async def login_user(user_creds: AuthCredentials):
    if user_creds.username in approved_users and approved_users[user_creds.username] == user_creds.password:
        return JSONResponse(content={"Response":"User is logged in."}, status_code=200)
    else:
        return JSONResponse(content={"Response":"Login failed."}, status_code=401)