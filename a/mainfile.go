package main

import (
    "encoding/json"
    "fmt"
    "os"
	"os/exec"
    "math/rand"
	"time"
)

func GenerateRandomString() string {
	const charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
	seededRand := rand.New(rand.NewSource(time.Now().UnixNano()))
	randomString := make([]byte, 10)
	for i := range randomString {
		randomString[i] = charset[seededRand.Intn(len(charset))]
	}
	return string(randomString)
}

// Create a struct for your JSON data
type MyData struct {
    KPI1  string `json:"kpi1"`
    KPI2 int    `json:"kpi2"`
	KPI3 int    `json:"kpi3"`
}

func main() {
    // Create and populate your JSON data
    rand.Seed(time.Now().UnixNano())
    kpi1 := GenerateRandomString()
	kpi2 := rand.Intn(100)
	kpi3 := rand.Intn(100)
    data := MyData{KPI1: kpi1, KPI2: kpi2, KPI3: kpi3}

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