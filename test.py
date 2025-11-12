from dotenv import load_dotenv
import os
import google.generativeai as genai

load_dotenv()
genai.configure(api_key=os.getenv("LLM_API_KEY"))
for m in genai.list_models():
    print(m.name)
