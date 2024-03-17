package com.example.data.entity.DTO;

public class DataDTO {
    private Float temp;

    public DataDTO(){
    }

    public DataDTO(Float temp){
        this.temp = temp;
    }

    public Float getTemp() {
        return temp;
    }

    public void setTemp(Float temp) {
        this.temp = temp;
    }
}
