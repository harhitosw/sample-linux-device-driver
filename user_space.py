def main():
    driver_handle = open('/proc/HarshDriver')
    msg_from_kernel = driver_handle.readline()
    print(msg_from_kernel)
    driver_handle.close()
    return 
main()