from fastapi import FastAPI, Form
from fastapi.responses import HTMLResponse, JSONResponse
import requests

app = FastAPI()

@app.get("/")

async def root():
    return {"Response" : "Hello World"}

@app.get("/auth_site", response_class=HTMLResponse)
async def login_user():
    html_content = """
    <html>
        <head>
            <title>Authentication Page</title>
        </head>
        <body>
            <h1>Welcome to the Authentication Page</h1>
            <form action="/login" method="post">
                <label for="username">Username:</label><br>
                <input type="text" id="username" name="username"><br>
                <label for="password">Password:</label><br>
                <input type="password" id="password" name="password"><br><br>
                <input type="submit" value="Login">
            </form> 
        </body>
    </html>
    """
    return HTMLResponse(content=html_content, status_code=200)

@app.post("/login")
async def login(username:str = Form(...), password:str=Form(...)):
    response = requests.post("http://localhost:8001/authenticate_user", json={"username":username, "password":password})
    if(response.status_code == 200):
        return JSONResponse(content=response.json(),status_code=200)
    else:
        return JSONResponse(content=response.json(), status_code=401)