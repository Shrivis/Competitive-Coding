import pyautogui as gui
import pytesseract
import time

top, left, width, height  = 233, 308, 833, 40


def take_screenshot(start_x, start_y, end_x, end_y):
    screenshot = gui.screenshot(region=(start_x, start_y, end_x, end_y))
    return screenshot

def recognize_text(screenshot):
    text = pytesseract.image_to_string(screenshot, lang='eng')
    return text

def type_text(text):
    gui.typewrite(text)
    # for word in text:
    #     time.sleep(0.001)
    #     gui.typewrite(word)

time.sleep(5)
gui.click(400, 444)

while(True):
    screenshot  = take_screenshot(top, left, width, height)
    text = recognize_text(screenshot)
    if (len(text)<50 or len(text)>100):
        break
    type_text(text)
    gui.typewrite(' ')