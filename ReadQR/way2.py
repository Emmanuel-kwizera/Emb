import cv2
from datetime import datetime
# set up camera object
cap = cv2.VideoCapture(0)
# QR code detection object
detector = cv2.QRCodeDetector()
f= open("found_data.txt", "w+")
while True:
    # get the image
    _, img = cap.read()
    # get bounding box coords and data
    data, bbox, _ = detector.detectAndDecode(img)
    # if there is a bounding box, draw one, along with the data
    if(bbox is not None):
        for i in range(len(bbox)):
            cv2.line(img, tuple(bbox[i][0]), tuple(bbox[(i+1) % len(bbox)][0]), color=(255,
                     0, 255), thickness=2)
        cv2.putText(img, data, (int(bbox[0][0][0]), int(bbox[0][0][1]) - 10), cv2.FONT_HERSHEY_SIMPLEX,
                    0.5, (0, 255, 0), 2)
        if data:
            print("data found: ", data)
            f.write("data: "+ data + " " + datetime.now().strftime("%d/%m/%Y %H:%M:%S")+"\n")
            
            file = open('qrcode-decoded.txt', 'w')
            file.write('Data found: '+data)
            file.close()
    # display the image preview
    cv2.imshow("code detector", img)
    if(cv2.waitKey(1) == ord("q")):
        break
# free camera object and exit
f.close()
cap.release()
cv2.destroyAllWindows()