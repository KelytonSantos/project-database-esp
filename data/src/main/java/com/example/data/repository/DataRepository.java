package com.example.data.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import com.example.data.entity.DataEntity;

@Repository
public interface DataRepository extends JpaRepository <DataEntity, Long> {
    
}
