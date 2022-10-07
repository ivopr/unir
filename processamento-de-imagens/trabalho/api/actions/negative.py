from PIL import Image
from io import BytesIO
import numpy

# b. Geração de negativo da imagem;
def negative(image):
  PILimage = Image.open(BytesIO(image))
  if (PILimage.mode == "RGB"):
    (R, G, B) = PILimage.split()
    R = numpy.asarray(R)
    G = numpy.asarray(G)
    B = numpy.asarray(B)

    # FAÇA AS ALTERAÇÕES EM R, G E B
    R = [[255 - r for r in row] for row in R]
    G = [[255 - r for r in row] for row in G]
    B = [[255 - r for r in row] for row in B]

    R = numpy.asarray(R)
    G = numpy.asarray(G)
    B = numpy.asarray(B)
    # END FAÇA AS ALTERAÇÕES EM R, G E B

    NPimage = numpy.zeros([PILimage.height, PILimage.width, 3], dtype=numpy.uint8)
    NPimage[:, :, 0] = R
    NPimage[:, :, 1] = G
    NPimage[:, :, 2] = B
  else:
    NPimage = numpy.asarray(PILimage.convert("L"))

    # FAÇA AS ALTERAÇÕES EM NPimage
    NPimage = [[255 - r for r in row] for row in NPimage]
    # END FAÇA AS ALTERAÇÕES EM NPimage

    NPimage = numpy.asarray(NPimage)

  # Transforma o array numpy (que é uma matriz) novamente em uma imagem
  # print(NPimage)
  PILimage = Image.fromarray(numpy.uint8(NPimage))
  return PILimage