
def parse(data, port, origin):
    if port==6667:
        return
    if origin == 'server':
        return
    print("[{}({})] {}".format(origin, port, data.encode('hex')))
