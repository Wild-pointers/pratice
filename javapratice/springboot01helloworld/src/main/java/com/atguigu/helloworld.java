package com.atguigu;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

/**
 * @Author LC
 * @Date 2020/5/17 11:27
 * @Version 1.0
 * @SpringBootApplication 来标注一个主程序类，说明这是一个spring boot应用
 */

@SpringBootApplication
public class helloworld {
    public static void main(String[] args) {

        //spring应用启动起来
        SpringApplication.run(helloworld.class,args);
    }
}
