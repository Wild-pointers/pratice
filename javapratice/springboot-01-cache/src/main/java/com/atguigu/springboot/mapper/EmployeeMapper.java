package com.atguigu.springboot.mapper;

import com.atguigu.springboot.bean.Employee;
import org.apache.ibatis.annotations.*;
import org.springframework.context.annotation.Bean;
import org.springframework.stereotype.Component;

/**
 * @Author LC
 * @Date 2020/8/6 17:23
 * @Version 1.0
 */
@Mapper
@Component
public interface EmployeeMapper {

    @Select("select * from employee where id=#{id}")
    public Employee getEmpById(Integer id);


    @Update("update employee set lastName=#{lastName},email=#{email},gender=#{gender},d_id=#{dId} where id=#{id}")
    public void updateEmp(Employee employee);


    @Delete("delete from employee where id=#{id}")
    public void deleteEmpById(Integer id);


    @Insert("insert into employee(lastName,email,gender,d_Id)values(#{lastName},#{email},#{gender},#{dId})")
    public void insertEmployee(Employee employee);


    @Select("select * from employee where lastName = #{lastName}")
    Employee getEmpByLastName(String lastName);
}
