package com.example.data.services;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.web.bind.annotation.GetMapping;

import com.example.data.entity.DataEntity;
import com.example.data.entity.DTO.DataDTO;
import com.example.data.repository.DataRepository;

@Service
public class DataService {
    
    @Autowired
    private DataRepository dataRepository;

    @GetMapping
    public List<DataEntity> findAll(){
        return dataRepository.findAll();
    }

    public DataEntity save(DataDTO dto) {
        DataEntity entity = new DataEntity();
        entity.setTemp(dto.getTemp()); 

        return dataRepository.save(entity);
    }

    public void deleteAll() {
        dataRepository.deleteAll();
    }
}
