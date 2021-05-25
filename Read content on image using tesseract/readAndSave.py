# from PIL import Image
# img = Image.open ('1.png')
# text = pytesseract.image_to_string(img, config='')
# print (text)

import os
cmd = "tesseract /home/pi/Desktop/2.jpeg stdout"
# output = os.system(cmd)
output = os.popen(cmd).read()
print(output)
f = open("imageData.txt","w+")
done = f.write("Image data " + output)

if done:
    print("data saved successfully")
else:
    print("Something went wrong while saving data to file")    