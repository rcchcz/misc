package main

import (
    "encoding/json"
    "fmt"
    "os"
	"os/exec"
)

// Create a struct for your JSON data
type MyData struct {
    KPI1  string `json:"kpi1"`
    KPI2 int    `json:"kpi2"`
	KPI3 int    `json:"kpi3"`
}

func main() {
    // Create and populate your JSON data
    data := MyData{KPI1: "abc", KPI2: 42, KPI3: -1}

    // Marshal the data into JSON format
    jsonData, err := json.Marshal(data)
    if err != nil {
        fmt.Println("Error marshaling JSON:", err)
        return
    }

    // Write the JSON data to a file
    err = os.WriteFile("metrics.json", jsonData, 0644)
    if err != nil {
        fmt.Println("Error writing JSON file:", err)
        return
    }

    fmt.Println("JSON data written to data.json")

	cmd := exec.Command("python3", "./script.py")
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr
	err = cmd.Run()
}