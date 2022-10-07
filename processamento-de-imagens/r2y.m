% ATIVIDADE 1 - 3

function [img] = r2y(image)
  pkg load image

  imageR = image(:, :, 1);
  imageG = image(:, :, 2);
  imageB = image(:, :, 3);

  imageY = 0.299 * imageR + 0.587 * imageG + 0.114 * imageB;
  imageI = 0.596 * imageR - 0.274 * imageG - 0.322 * imageB;
  imageQ = 0.211 * imageR - 0.523 * imageG + 0.312 * imageB;

  img = zeros(size(image));
  img(:, :, 1) = imageY;
  img(:, :, 2) = imageI;
  img(:, :, 3) = imageQ;

  % Na conversão, a imagem resultado 'img' possui uma tonalidade mais rosada
  % enquanto a gerada pela função 'rgb2ntsc' tem uma tonalidade mais marrom
  figure, imshow([img/255 rgb2ntsc(image)]);
endfunction
