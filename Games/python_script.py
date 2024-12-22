from PIL import Image
import os

def rgb_to_rgb565(r, g, b):
    # Convert 8-bit RGB to 16-bit RGB565
    return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3)

def extract_rgb565_from_image(image_path, output_file):
    try:
        # Open the image
        img = Image.open(image_path)
        # Ensure the image is in RGB mode
        img = img.convert("RGB")

        # Get pixel data
        pixels = list(img.getdata())

        # Convert RGB tuples to RGB565 hexadecimal format
        rgb565_values = ",".join([f"0x{rgb_to_rgb565(r, g, b):04X}" for r, g, b in pixels])

        # Write to output file
        with open(output_file, "w") as file:
            file.write(rgb565_values)

        print(f"RGB565 values extracted and saved to {output_file}")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    # Input image path
    image_path = input("Enter the path to the image: ").strip()
    # Output file path
    output_file = input("Enter the path to the output file: ").strip()

    if not os.path.isfile(image_path):
        print("The specified image file does not exist.")
    else:
        extract_rgb565_from_image(image_path, output_file)
