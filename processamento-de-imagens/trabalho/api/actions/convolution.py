from PIL import Image
from io import BytesIO
import numpy

# g. Convolução entre uma imagem f e uma máscara h, com offset, tal que 
# g = f*h+offset. O sistema deverá permitir que o usuário especifique a 
# imagem f e, via interface gráfica ou arquivo com formatação específica, 
# os valores dos elementos de h (n x m). Considere nulos os valores 
# indefinidos de fi,j e hi,j.
def convolve(image):
  PILimage = Image.open(BytesIO(image))
  X = numpy.asarray(PILimage.convert("L"))
  F = numpy.array([[0.1, 0.1, 0.1],[0.1, 0.1, 0.1],[0.1, 0.1, 0.1]])

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
  PILimage = Image.fromarray(numpy.uint8(out))
  return PILimage
