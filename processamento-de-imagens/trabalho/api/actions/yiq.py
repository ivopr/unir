from base64 import b64encode
from io import BytesIO
from PIL import Image
import numpy

# a. Conversão RGB-YIQ-RGB;
def rgb_to_yiq(image):
  PILimage = Image.open(BytesIO(image))
  if (PILimage.mode == "RGB"):
    (R, G, B) = PILimage.split()
    R = numpy.asarray(R)
    G = numpy.asarray(G)
    B = numpy.asarray(B)

    # FAÇA AS ALTERAÇÕES EM R, G E B
    Y = 0.299 * R + 0.587 * G + 0.114 * B
    I = 0.596 * R - 0.274 * G - 0.322 * B
    Q = 0.211 * R - 0.523 * G + 0.312 * B
    # END FAÇA AS ALTERAÇÕES EM R, G E B

    NPimage = numpy.zeros([PILimage.height, PILimage.width, 3], dtype=numpy.uint8)
    NPimage[:, :, 0] = Y
    NPimage[:, :, 1] = I
    NPimage[:, :, 2] = Q
  else:
    # Se for uma imagem em escala de cinza, não faz nada
    NPimage = numpy.asarray(PILimage.convert("L"))

  # Transforma o array numpy (que é uma matriz) novamente em uma imagem
  PILimage = Image.fromarray(numpy.uint8(NPimage))
  return PILimage

def yiq_to_rgb(image):
  PILimage = Image.open(BytesIO(image))
  if (PILimage.mode == "RGB"):
    (Y, I, Q) = PILimage.split()
    Y = numpy.asarray(Y)
    I = numpy.asarray(I)
    Q = numpy.asarray(Q)

    # FAÇA AS ALTERAÇÕES EM R, G E B
    R = 1 * Y + 0.956 * I + 0.621 * Q
    G = 1 * Y - 0.272 * I - 0.647 * Q
    B = 1 * Y - 1.106 * I + 1.703 * Q
    # END FAÇA AS ALTERAÇÕES EM R, G E B

    NPimage = numpy.zeros([PILimage.height, PILimage.width, 3], dtype=numpy.uint8)
    NPimage[:, :, 0] = R
    NPimage[:, :, 1] = G
    NPimage[:, :, 2] = B
  else:
    NPimage = numpy.asarray(PILimage.convert("L"))

  # Transforma o array numpy (que é uma matriz) novamente em uma imagem
  PILimage = Image.fromarray(numpy.uint8(NPimage))
  return PILimage