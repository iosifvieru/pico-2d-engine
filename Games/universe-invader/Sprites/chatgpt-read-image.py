from PIL import Image

def rgb888_to_rgb565(r, g, b):
    """
    Convert RGB888 to RGB565.
    :param r: Red component (0-255)
    :param g: Green component (0-255)
    :param b: Blue component (0-255)
    :return: RGB565 value
    """
    return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3)

def convert_image_to_rgb565(image_path, output_path, columns=16):
    """
    Convert an image to RGB565 format and save the result to a file.
    :param image_path: Path to the input image (.jpg)
    :param output_path: Path to the output file
    :param columns: Number of columns per row in the output file
    """
    # Open the image
    image = Image.open(image_path).convert("RGB")
    
    # Get the image dimensions
    width, height = image.size

    # Open the output file
    with open(output_path, "w") as file:
        for y in range(height):
            row_data = []
            for x in range(width):
                # Get the RGB values of the pixel
                r, g, b = image.getpixel((x, y))

                # Convert to RGB565
                rgb565 = rgb888_to_rgb565(r, g, b)

                # Append the value as a hexadecimal string
                row_data.append(f"0x{rgb565:04X}")

                # Add a new line after every `columns` pixels
                if len(row_data) == columns:
                    file.write(", ".join(row_data) + "\n")
                    row_data = []

            # Write any remaining data in the row
            if row_data:
                file.write(", ".join(row_data) + "\n")

if __name__ == "__main__":
    # Input and output paths
    input_image = "explosion.png"  # Change this to your input file
    output_file = "output_rgb565.txt"  # Change this to your desired output file

    # Convert the image and save the RGB565 values
    convert_image_to_rgb565(input_image, output_file)
    print(f"RGB565 data has been written to {output_file}")
