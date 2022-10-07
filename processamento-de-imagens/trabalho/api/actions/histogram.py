from PIL import Image
from io import BytesIO
import numpy

# d. Expansão e equalização do histograma;
def expansion(image):
  PILimage = Image.open(BytesIO(image))
  if (PILimage.mode == "RGB"):
    (R, G, B) = PILimage.split()
    R = numpy.asarray(R)
    G = numpy.asarray(G)
    B = numpy.asarray(B)

    # FAÇA AS ALTERAÇÕES EM R, G E B
    rmin = R.min()
    rmax = R.max()
    R = [[(((r - rmin) * 1) / (rmax - rmin)) for r in row] for row in R]
    
    gmin = G.min()
    gmax = G.max()
    G = [[(((r - gmin) * 1) / (gmax - gmin)) for r in row] for row in G]
    
    bmin = B.min()
    bmax = B.max()
    B = [[(((r - bmin) * 1) / (bmax - bmin)) for r in row] for row in B]

    R = numpy.asarray(R) * 255
    G = numpy.asarray(G) * 255
    B = numpy.asarray(B) * 255
    # END FAÇA AS ALTERAÇÕES EM R, G E B

    NPimage = numpy.zeros([PILimage.height, PILimage.width, 3], dtype=numpy.uint8)
    NPimage[:, :, 0] = R
    NPimage[:, :, 1] = G
    NPimage[:, :, 2] = B
  else:
    NPimage = numpy.asarray(PILimage.convert("L"))

    # FAÇA AS ALTERAÇÕES EM NPimage
    npmin = NPimage.min()
    npmax = NPimage.max()
    NPimage = [[(((r - npmin) * 1) / (npmax - npmin)) for r in row] for row in NPimage]
    NPimage = numpy.asarray(NPimage) * 255
    # END FAÇA AS ALTERAÇÕES EM NPimage

  # Transforma o array numpy (que é uma matriz) novamente em uma imagem
  PILimage = Image.fromarray(numpy.uint8(NPimage))
  return PILimage

def equalization(image):
  PILimage = Image.open(BytesIO(image))
  if (PILimage.mode == "RGB"):
    (R, G, B) = PILimage.split()
    R = numpy.asarray(R)
    G = numpy.asarray(G)
    B = numpy.asarray(B)

    # FAÇA AS ALTERAÇÕES EM R, G E B
    h_b, bin_b = numpy.histogram(B.flatten(), 256, [0, 256])
    h_g, bin_g = numpy.histogram(G.flatten(), 256, [0, 256])
    h_r, bin_r = numpy.histogram(R.flatten(), 256, [0, 256])

    cdf_b = numpy.cumsum(h_b)  
    cdf_g = numpy.cumsum(h_g)
    cdf_r = numpy.cumsum(h_r)

    cdf_m_b = numpy.ma.masked_equal(cdf_b,0)
    cdf_m_b = (cdf_m_b - cdf_m_b.min())*255/(cdf_m_b.max()-cdf_m_b.min())
    cdf_final_b = numpy.ma.filled(cdf_m_b,0).astype('uint8')
  
    cdf_m_g = numpy.ma.masked_equal(cdf_g,0)
    cdf_m_g = (cdf_m_g - cdf_m_g.min())*255/(cdf_m_g.max()-cdf_m_g.min())
    cdf_final_g = numpy.ma.filled(cdf_m_g,0).astype('uint8')

    cdf_m_r = numpy.ma.masked_equal(cdf_r,0)
    cdf_m_r = (cdf_m_r - cdf_m_r.min())*255/(cdf_m_r.max()-cdf_m_r.min())
    cdf_final_r = numpy.ma.filled(cdf_m_r,0).astype('uint8')
    
    img_b = cdf_final_b[B]
    img_g = cdf_final_g[G]
    img_r = cdf_final_r[R]
    # END FAÇA AS ALTERAÇÕES EM R, G E B

    NPimage = numpy.zeros([PILimage.height, PILimage.width, 3], dtype=numpy.uint8)
    NPimage[:, :, 0] = img_r
    NPimage[:, :, 1] = img_g
    NPimage[:, :, 2] = img_b
  else:
    NPimage = numpy.asarray(PILimage.convert("L"))

    # FAÇA AS ALTERAÇÕES EM NPimage

    # END FAÇA AS ALTERAÇÕES EM NPimage

  # Transforma o array numpy (que é uma matriz) novamente em uma imagem
  PILimage = Image.fromarray(numpy.uint8(NPimage))
  return PILimage