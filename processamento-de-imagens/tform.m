function J = tform(in, type)
  pkg load image;
  if type == "cisver"
    tform = maketform("affine", [1 0 0; 0.5 1 0; 0 0 1]);
  elseif type == "cishor"
    tform = maketform("affine", [1 0.5 0; 0 1 0; 0 0 1]);
  endif

  J = imtransform(in, tform);
  figure, imshow(J);
endfunction
