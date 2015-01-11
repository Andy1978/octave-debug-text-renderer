#axes ("xtick", [1], "ytick", [], "ztick", [], "xticklabel", "xtick1")
#text (0.5, 0.5, "hello world")

#img = render_text ("Hello world!", "none");
img = render_text ("first \\omega\nhello_{sub}^{super}", "tex");
tmp = rot90 (squeeze (img(4, :, :)));
imshow (tmp)
