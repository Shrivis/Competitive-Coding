from PIL import Image



def map_value(value, in_min, in_max, out_min, out_max):
    return (value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min




# ascii = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,^`'."
ascii = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~i!lI;:,^`'.                          "
# ascii = " .°*oO#@"
# ascii = ascii[::-1]

# Get the pixel values in top right to left bottom order

with open('index.html', 'w') as file:
    html = '''<!doctype html><html lang="en"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width, initial-scale=1"><link  href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet"><link href="https://fonts.googleapis.com/css?family=Courier Prime" rel="stylesheet"><style> body {margin:0; font-family: "Courier Prime"; font-size: 8px;} .size { height: 8px; margin: 0; width: 8px; overflow: hidden;} div{margin:0; padding:0}}</style><title>ASCII Art</title></head><body><div class="mt-4">'''
    
    file.write(html);

    # Open the image
    image = Image.open("./hand.jpeg")

    # Resize the image 
    width, height = image.size
    new_width = 100
    new_height = int(height * new_width / width)
    resized_image = image.resize((new_width, new_height))

    for y in range(0, new_height):
        ascii_image = '<div class="d-flex">'
        for x in range(0, new_width):
            r, g, b, *args = resized_image.getpixel((x, y))
            # r, g, b = resized_image.getpixel((x, y)) # uncomment this line a commnet the above line for jpeg or jpg images
            # original_value = (r+g+b)/3
            original_value = r*0.3 + g*0.59 + b*0.11
            mapped_value = int(map_value(original_value, 0, 255, 0, len(ascii)-1))
            if (ascii[mapped_value] != ' '):
                ascii_image += f'<p class="size">{ascii[mapped_value]}</p>'
            else:
                ascii_image += f'<p class="size">&nbsp</p>'
        ascii_image += "</div>"
        file.write(ascii_image)

    file.write('</div><script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js"></script></body></html>')
