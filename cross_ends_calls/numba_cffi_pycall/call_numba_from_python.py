from cffi_interface import call_add

def main():
    x = 2.0
    y = 3.0
    result = call_add(x, y)
    print(f"The result of adding {x} and {y} is {result}")

if __name__ == "__main__":
    main()
