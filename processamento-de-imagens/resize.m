pkg load image;

im = imread("images/lena512.bmp");
viz = imresize(im, 0.5, "nearest");
bil = imresize(im, 0.5, "bilinear");
bic = imresize(im, 0.5, "bicubic");

figure, imshow([viz bil bic]); title("vizinho - bilinear - bicubico");
