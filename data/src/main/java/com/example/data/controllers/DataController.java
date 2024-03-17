package com.example.data.controllers;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseStatus;
import org.springframework.web.bind.annotation.RestController;

import com.example.data.services.DataService;
import com.example.data.entity.DTO.DataDTO;
import com.example.data.entity.DataEntity;


@RestController
@RequestMapping("/api/data")
public class DataController {
    
    @Autowired
    private DataService dataService;
    
    @GetMapping
    public List<DataEntity> findAll(){
        return dataService.findAll();
    }

    @PostMapping
    @ResponseStatus(HttpStatus.CREATED)
    public DataEntity save(@RequestBody DataDTO dto){
        return dataService.save(dto);
    }

    @DeleteMapping("/deleteAll")
    public void deleteAll() {
        dataService.deleteAll();
    }
}
