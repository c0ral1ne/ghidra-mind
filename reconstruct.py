from dotenv import load_dotenv
from openai import OpenAI
from time import time
import tiktoken

PROMPT = """Reconstruct the below decompiled C code to make it more readable. Specifically: rename variables, remove stack canary checks (include a comment that you did this), remove #include statements
DO NOT modify any logic. Only output the C code, nothing else.
{code}
"""

load_dotenv()
CLIENT = OpenAI()
MODEL = 'gpt-5'

def get_token_count(input):
    encoding = tiktoken.encoding_for_model(MODEL)
    tokens = encoding.encode(input)
    return len(tokens)

def reconstruct(code):
    response = CLIENT.responses.create(
        model=MODEL,
        instructions="Your role is to reconstruct bare decompiled C code to something readable and user-friendly.",
        input=PROMPT.format(code=code),
    )

    with open(f'output/output_{round(time())}.c', 'w') as file:
        file.write(response.output_text)

    return response.output_text
