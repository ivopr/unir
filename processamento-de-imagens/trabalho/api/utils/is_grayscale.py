from io import BytesIO
from PIL import Image, ImageStat


def is_grayscale(image):
    im = Image.open(BytesIO(image)).convert("RGB")
    stat = ImageStat.Stat(im)
    if sum(stat.sum) / 3 == stat.sum[0]: # check the avg with any element value
        return True # if grayscale
    else:
        return False # else its colour