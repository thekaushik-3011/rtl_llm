import os
import time
from dotenv import load_dotenv
import google.generativeai as genai

def load_llm():
    """Initialize LLM connection using Gemini API key."""
    load_dotenv()
    api_key = os.getenv("LLM_API_KEY")
    if not api_key:
        raise ValueError("Missing LLM_API_KEY in .env file")
    genai.configure(api_key=api_key)
    return genai.GenerativeModel("models/gemini-2.5-flash")

def save_file(path, content):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "w") as f:
        f.write(content)
    print(f"[INFO] File saved: {path}")

def read_file(path):
    with open(path, "r") as f:
        return f.read()

def timestamp():
    return time.strftime("%Y-%m-%d_%H-%M-%S")
