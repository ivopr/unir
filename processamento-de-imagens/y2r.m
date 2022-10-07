% ATIVIDADE 1 - 4


function [img] = y2r(image)
  pkg load image

  imageY = image(:, :, 1);
  imageI = image(:, :, 2);
  imageQ = image(:, :, 3);

  imageR = 1 * imageY + 0.956 * imageI + 0.621 * imageQ;
  imageG = 1 * imageY - 0.272 * imageI - 0.647 * imageQ;
  imageB = 1 * imageY - 1.106 * imageI + 1.703 * imageQ;

  img = zeros(size(image));
  img(:, :, 1) = imageR;
  img(:, :, 2) = imageG;
  img(:, :, 3) = imageB;

  figure, imshow([img/255 ntsc2rgb(image)]);
endfunction
