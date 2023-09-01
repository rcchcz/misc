import json

def main():
    print("inside python script")
    # Read the JSON data from the file
    with open('metrics.json', 'r') as file:
        data = json.load(file)

    # Process the JSON data
    print("kpi1:", data['kpi1'])
    print("kpi2:", data['kpi2'])
    print("kpi3:", data['kpi3'])

if __name__ == "__main__":
    main()