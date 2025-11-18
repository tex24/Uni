from cerebras.cloud.sdk import Cerebras

client = Cerebras(
    api_key='csk-3xmy34v2nw625tefr8en26p53phmpn26hvfrknpcmk4efxcr'
)

completion = client.chat.completions.create(
    messages=[{"role":"user","content":"Why is fast inference important?"}],
    model="llama-3.3-70b",
    max_completion_tokens=1024,
    temperature=0.2,
    top_p=1,
    stream=False
)

print(completion.choices[0].message.content)