from base64 import b64encode
from io import BytesIO, StringIO
from fastapi import FastAPI, File, Form, Request, UploadFile, Response
import uvicorn
from actions.adaptive_contrast import adaptive_contrast
from actions.histogram import equalization, expansion
from actions.mean_median import mean, median
from actions.negative import negative
from actions.sobel_gradient import sobel_gradient
from actions.convolution import convolve

from actions.yiq import rgb_to_yiq, yiq_to_rgb

app = FastAPI()

# Para retornar a imagem ao inves da base64
# return Response(content = bytes_image.getvalue(), media_type="image/png")

@app.get("/")
async def root():
    return {"message": "Hello World"}

@app.post("/rgb-yiq")
async def RGB_to_YIQ(file: UploadFile = File(...)):
    ret = rgb_to_yiq(await file.read())
    bytes_image = BytesIO()
    ret.save(bytes_image, format="PNG")

    img_str = b64encode(bytes_image.getvalue())

    return img_str

@app.post("/yiq-rgb")
async def YIQ_to_RGB(file: UploadFile = File(...)):
    ret = yiq_to_rgb(await file.read())
    bytes_image = BytesIO()
    ret.save(bytes_image, format="PNG")

    img_str = b64encode(bytes_image.getvalue())

    return img_str

@app.post("/negative")
async def image_negative(file: UploadFile = File(...)):
    ret = negative(await file.read())
    bytes_image = BytesIO()
    ret.save(bytes_image, format="PNG")

    img_str = b64encode(bytes_image.getvalue())

    return img_str


@app.post("/expansion")
async def histogram_expansion(file: UploadFile = File(...)):
    ret = expansion(await file.read())
    bytes_image = BytesIO()
    ret.save(bytes_image, format="PNG")

    img_str = b64encode(bytes_image.getvalue())

    return img_str

@app.post("/equalization")
async def histogram_equalization(file: UploadFile = File(...)):
    ret = equalization(await file.read())
    bytes_image = BytesIO()
    ret.save(bytes_image, format="PNG")

    img_str = b64encode(bytes_image.getvalue())

    return img_str

@app.post("/sobel")
async def sobel(file: UploadFile = File(...)):
    ret = sobel_gradient(await file.read())
    bytes_image = BytesIO()
    ret.save(bytes_image, format="PNG")

    img_str = b64encode(bytes_image.getvalue())
    # return Response(content = bytes_image.getvalue(), media_type="image/png")

    return img_str

@app.post("/mean")
async def mean_filter(file: UploadFile = File(...), n: int = Form(3)):
    ret = mean(await file.read(), n)
    bytes_image = BytesIO()
    ret.save(bytes_image, format="PNG")

    img_str = b64encode(bytes_image.getvalue())
    # return Response(content = bytes_image.getvalue(), media_type="image/png")

    return img_str

@app.post("/median")
async def median_filter(file: UploadFile = File(...), n: int = Form(3)):
    ret = median(await file.read(), n)
    bytes_image = BytesIO()
    ret.save(bytes_image, format="PNG")

    img_str = b64encode(bytes_image.getvalue())
    # return Response(content = bytes_image.getvalue(), media_type="image/png")

    return img_str

@app.post("/contrast")
async def contrast(file: UploadFile = File(...), n: int = Form(3), c: int = Form(1)):
    ret = adaptive_contrast(await file.read(), c, n)
    bytes_image = BytesIO()
    ret.save(bytes_image, format="PNG")

    img_str = b64encode(bytes_image.getvalue())
    # return Response(content = bytes_image.getvalue(), media_type="image/png")

    return img_str


@app.post("/convolution")
async def conv_filter(file: UploadFile = File(...)):
    ret = convolve(await file.read())
    bytes_image = BytesIO()
    ret.save(bytes_image, format="PNG")

    img_str = b64encode(bytes_image.getvalue())
    return img_str
    #return Response(content = bytes_image.getvalue(), media_type="image/png")
