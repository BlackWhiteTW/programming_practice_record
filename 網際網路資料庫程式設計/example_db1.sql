-- phpMyAdmin SQL Dump
-- version 2.10.2
-- http://www.phpmyadmin.net
-- 
-- 主機: localhost
-- 建立日期: May 30, 2014, 09:35 AM
-- 伺服器版本: 5.0.45
-- PHP 版本: 5.2.3
-- 
-- 資料庫: `example_db1`
-- 
CREATE DATABASE `example_db1` DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci;
USE `example_db1`;

-- --------------------------------------------------------

-- 
-- 資料表格式： `users`
-- 

CREATE TABLE `users` (
  `user_id` varchar(10) NOT NULL,
  `user_pwd` varchar(10) NOT NULL,
  `user_name` varchar(10) NOT NULL,
  `id_no` varchar(10) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- 
-- 列出以下資料庫的數據： `users`
-- 

INSERT INTO `users` VALUES ('andy', 'andy1234', '吳安迪', 'N121567723');
INSERT INTO `users` VALUES ('amy', 'amy123', '張郁樺', 'N223023254');
