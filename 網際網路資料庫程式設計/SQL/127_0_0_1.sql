-- phpMyAdmin SQL Dump
-- version 4.8.5
-- https://www.phpmyadmin.net/
--
-- 主機： 127.0.0.1
-- 產生時間： 
-- 伺服器版本： 10.1.38-MariaDB
-- PHP 版本： 7.3.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- 資料庫： `school`
--
CREATE DATABASE IF NOT EXISTS `school` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `school`;

-- --------------------------------------------------------

--
-- 資料表結構 `course`
--

CREATE TABLE `course` (
  `stdno` varchar(8) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
  `course` varchar(20) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- 傾印資料表的資料 `course`
--

INSERT INTO `course` (`stdno`, `course`) VALUES
('S1254051', '英文'),
('S1254051', '線性代數'),
('S1254053', '英文'),
('S1254054', '英文'),
('S1254054', '微積分');

-- --------------------------------------------------------

--
-- 資料表結構 `students`
--

CREATE TABLE `students` (
  `stdno` varchar(8) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
  `name` varchar(12) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
  `address` varchar(50) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
  `birthday` date NOT NULL,
  `totalcredit` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- 傾印資料表的資料 `students`
--

INSERT INTO `students` (`stdno`, `name`, `address`, `birthday`, `totalcredit`) VALUES
('S1254051', '王小明', '台中市西屯區', '1980-01-05', 18),
('S1254052', '楊中平', '台中市北屯區', '1977-11-22', 20),
('S1254053', '陳大器', '台中市南屯區', '1980-05-15', 22),
('S1254054', '林無雙', '彰化縣彰化市', '1981-08-01', 18);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
