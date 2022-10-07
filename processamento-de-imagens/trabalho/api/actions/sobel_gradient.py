from PIL import Image
from io import BytesIO
import numpy

def convolve(X, F):
  # height and width of the image
  X_height = X.shape[0]
  X_width = X.shape[1]
  
  # height and width of the filter
  F_height = F.shape[0]
  F_width = F.shape[1]
  
  H = (F_height - 1) // 2
  W = (F_width - 1) // 2
  
  #output numpy matrix with height and width
  out = numpy.zeros((X_height, X_width))
  #iterate over all the pixel of image X
  for i in numpy.arange(H, X_height-H):
    for j in numpy.arange(W, X_width-W):
      sum = 0
      #iterate over the filter
      for k in numpy.arange(-H, H+1):
        for l in numpy.arange(-W, W+1):
          #get the corresponding value from image and filter
          a = X[i+k, j+l]
          w = F[H+k, W+l]
          sum += (w * a)
      out[i,j] = sum
  #return convolution  
  return out

# f. Gradiente de Sobel;
def sobel_gradient(image):
  PILimage = Image.open(BytesIO(image))
  NPimage = numpy.asarray(PILimage.convert("L"))

  # FAÇA AS ALTERAÇÕES EM NPimage
  Gx = numpy.array([[-1, 0, 1],[-2, 0, 2],[-1, 0, 1]])
  Gy = numpy.array([[-1, -2, -1],[0, 0, 0],[1, 2, 1]])
  sob_x = convolve(NPimage, Gx) / 8.0
  sob_y = convolve(NPimage, Gy) / 8.0
  sob_out = numpy.sqrt(numpy.power(sob_x, 2) + numpy.power(sob_y, 2))
  sob_out = (sob_out / numpy.max(sob_out)) * 255
  # END FAÇA AS ALTERAÇÕES EM NPimage

  # Transforma o array numpy (que é uma matriz) novamente em uma imagem
  PILimage = Image.fromarray(numpy.uint8(sob_out))
  return PILimage