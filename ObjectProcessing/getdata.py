import serial


# Configure the serial port
ser = serial.Serial('/dev/ttyACM0', 9600) # replace ttyUSB0 with the correct serial port and 9600 with the correct baud rate

# Read the serial data


def returnMode():
    try:
        data = ser.readline().decode().strip()
        return int(data)
    except:
        return 0

# while True:
#     print(returnMode())

# while True:
#     data = ser.readline()
#     print(type(data))
#     print("Data")
#     print(data)
#     try:
#         data = data.decode().strip()
#         print("Data after strip")
#         print(data)
#     except:
#         pass
    # print("Data after strip")
    # print(data)
    # if data != "":
    #     result = int(data)
    #     print("result")
    #     print(result)

# while True:
#     print(returnMode())

# class ReadLine:
#     def __init__(self, s):
#         self.buf = bytearray()
#         self.s = s

#     def readline(self):
#         i = self.buf.find(b"\n")
#         if i >= 0:
#             r = self.buf[:i+1]
#             self.buf = self.buf[i+1:]
#             return r
#         while True:
#             i = max(1, min(2048, self.s.in_waiting))
#             data = self.s.read(i)
#             i = data.find(b"\n")
#             if i >= 0:
#                 r = self.buf + data[:i+1]
#                 self.buf[0:] = data[i+1:]
#                 return r
#             else:
#                 self.buf.extend(data)

# ser = serial.Serial('/dev/ttyACM0', 9600)

# def returnMode():
#     rl = ReadLine(ser)
#     rl.readline()
#     rl.readline()
#     rl.readline()
#     return int(str(rl.readline())[12])

# # print(ser.name)
# # rl = ReadLine(ser)
# # count = 0
# # while True:
# #     returnMode()
# #     print(returnMode())