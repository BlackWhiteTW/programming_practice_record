-- phpMyAdmin SQL Dump
-- version 2.8.2
-- http://www.phpmyadmin.net
-- 
-- 主機: localhost
-- 建立日期: May 26, 2010, 06:33 AM
-- 伺服器版本: 5.0.22
-- PHP 版本: 5.1.4
-- 
-- 資料庫: `school`
-- 
CREATE DATABASE `school` DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci;
USE `school`;

-- --------------------------------------------------------

-- 
-- 資料表格式： `students`
-- 

CREATE TABLE `students` (
  `stud_no` varchar(10) NOT NULL,
  `stud_name` varchar(10) NOT NULL,
  `stud_sex` varchar(2) NOT NULL,
  `stud_addr` varchar(20) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- 
-- 列出以下資料庫的數據： `students`
-- 

INSERT INTO `students` VALUES ('93830002', '陳美秀', 'F', '彰化縣');
INSERT INTO `students` VALUES ('93830008', '李美玲', 'F', '台中市');
INSERT INTO `students` VALUES ('93830011', '李佩珊', 'F', '宜蘭縣');
INSERT INTO `students` VALUES ('93830020', '葉君偉', 'M', '嘉義市');
INSERT INTO `students` VALUES ('93830021', '林信豪', 'M', '高雄縣');
INSERT INTO `students` VALUES ('93830024', '吳婉瑜', 'F', '彰化縣');
INSERT INTO `students` VALUES ('93830026', '曾育如', 'F', '台中市');
INSERT INTO `students` VALUES ('93830031', '江如雪', 'F', '桃園縣');
INSERT INTO `students` VALUES ('93830032', '彭文豪', 'M', '桃園市');
INSERT INTO `students` VALUES ('93830034', '林志堅', 'M', '宜蘭市');
INSERT INTO `students` VALUES ('93830037', '張志銘', 'M', '台北縣');
INSERT INTO `students` VALUES ('93830038', '吳貞君', 'M', '台北縣');
INSERT INTO `students` VALUES ('93830041', '蘇怡蓉', 'F', '台北縣');
INSERT INTO `students` VALUES ('93830046', '陳昌宏', 'M', '台南縣');
INSERT INTO `students` VALUES ('93830047', '林志豪', 'M', '高雄縣');
INSERT INTO `students` VALUES ('94830001', '廖孟哲', 'M', '台北縣');
INSERT INTO `students` VALUES ('94830002', '陳為民', 'F', '彰化縣');
INSERT INTO `students` VALUES ('94830004', '黃彥廷', 'M', '高雄縣');
INSERT INTO `students` VALUES ('94830006', '李明治', 'M', '高雄市');
INSERT INTO `students` VALUES ('94830007', '鐘維哲', 'M', '台北縣');
INSERT INTO `students` VALUES ('94830008', '周靜慧', 'F', '台南縣');
INSERT INTO `students` VALUES ('94830011', '陳明志', 'M', '宜蘭縣');
INSERT INTO `students` VALUES ('94830013', '蔡文祥', 'M', '台中市');
INSERT INTO `students` VALUES ('94830015', '徐芳如', 'F', '嘉義縣');
INSERT INTO `students` VALUES ('94830017', '李世美', 'M', '台北市');
INSERT INTO `students` VALUES ('94830019', '紀淑英', 'M', '台中縣');
INSERT INTO `students` VALUES ('94830021', '林育平', 'M', '台中縣');
INSERT INTO `students` VALUES ('94830022', '林玉敏', 'M', '台中縣');
INSERT INTO `students` VALUES ('94830024', '吳一凡', 'M', '宜蘭縣');
INSERT INTO `students` VALUES ('94830028', '潘世明', 'M', '高雄縣');
INSERT INTO `students` VALUES ('94830031', '謝佳玲', 'M', '台南縣');
INSERT INTO `students` VALUES ('94830034', '劉美娟', 'F', '新竹縣');
INSERT INTO `students` VALUES ('94830036', '詹瑞明', 'M', '桃園縣');
INSERT INTO `students` VALUES ('94830037', '張文傑', 'M', '桃園縣');
INSERT INTO `students` VALUES ('94830038', '林明毅', 'M', '桃園縣');
INSERT INTO `students` VALUES ('94830039', '簡建宏', 'M', '台北縣');
INSERT INTO `students` VALUES ('94830040', '陳明芬', 'F', '台北縣');
INSERT INTO `students` VALUES ('94830042', '吳偉誠', 'M', '台北市');
INSERT INTO `students` VALUES ('94830043', '連幸瑜', 'M', '台北市');
INSERT INTO `students` VALUES ('94830045', '陳志仁', 'M', '台北縣');
INSERT INTO `students` VALUES ('94830046', '陳怡婷', 'F', '台中縣');
INSERT INTO `students` VALUES ('94830047', '洪明陽', 'M', '台中市');
INSERT INTO `students` VALUES ('94830048', '林信正', 'M', '彰化縣');
INSERT INTO `students` VALUES ('94830049', '許宏亮', 'M', '彰化縣');
INSERT INTO `students` VALUES ('94830050', '賴士民', 'M', '台中市');
INSERT INTO `students` VALUES ('94830052', '葉文廷', 'M', '台北縣');
INSERT INTO `students` VALUES ('94830054', '張育民', 'M', '雲林縣');
INSERT INTO `students` VALUES ('94830055', '郭依佳', 'M', '嘉義市');
INSERT INTO `students` VALUES ('94830056', '連和興', 'M', '台中縣');
INSERT INTO `students` VALUES ('94830057', '黃瑞霞', 'F', '台中市');


