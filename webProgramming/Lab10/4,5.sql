-- phpMyAdmin SQL Dump
-- version 3.2.3
-- http://www.phpmyadmin.net
--
-- 호스트: localhost
-- 처리한 시간: 15-11-24 11:14 
-- 서버 버전: 5.1.41
-- PHP 버전: 5.2.12

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- 데이터베이스: `final3`
--

-- --------------------------------------------------------

--
-- 테이블 구조 `actors`
--

CREATE TABLE IF NOT EXISTS `actors` (
  `id` int(11) NOT NULL,
  `first_name` varchar(20) CHARACTER SET euckr NOT NULL,
  `last_name` varchar(20) CHARACTER SET euckr NOT NULL,
  `gender` varchar(5) CHARACTER SET euckr NOT NULL,
  KEY `id` (`id`),
  KEY `id_2` (`id`),
  KEY `id_3` (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- 테이블의 덤프 데이터 `actors`
--

INSERT INTO `actors` (`id`, `first_name`, `last_name`, `gender`) VALUES
(1, 'Bill', 'Allison', 'M'),
(2, 'Anthony', 'Allison', 'M'),
(3, 'Frankie J.', 'Allison', 'M'),
(4, 'J. Todd', 'Anderson', 'M'),
(5, 'Elenor', 'Witt', 'F'),
(6, 'Rowan', 'Witt', 'F'),
(7, 'Ben (I)', 'Wright', 'F'),
(8, 'Samuel E.', 'Wright', 'M');

-- --------------------------------------------------------

--
-- 테이블 구조 `movies`
--

CREATE TABLE IF NOT EXISTS `movies` (
  `id` int(11) NOT NULL,
  `name` varchar(20) NOT NULL,
  `year` int(11) NOT NULL,
  `rating` float NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- 테이블의 덤프 데이터 `movies`
--

INSERT INTO `movies` (`id`, `name`, `year`, `rating`) VALUES
(100, 'Ocean''s Eleven', 2000, 8),
(101, 'Fight Club', 1999, 9),
(102, 'Fargo', 2003, 9.5),
(103, 'Matrix, The', 2010, 8),
(104, 'Little Mermaid, The', 1998, 9),
(105, 'Memento', 2000, 8.7);

-- --------------------------------------------------------

--
-- 테이블 구조 `roles`
--

CREATE TABLE IF NOT EXISTS `roles` (
  `actor_id` int(11) NOT NULL,
  `movie_id` int(11) NOT NULL,
  `role` varchar(20) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- 테이블의 덤프 데이터 `roles`
--

INSERT INTO `roles` (`actor_id`, `movie_id`, `role`) VALUES
(1, 100, 'man1'),
(2, 100, 'man2'),
(3, 100, 'man3'),
(4, 102, 'man1'),
(5, 103, 'girl1'),
(6, 103, 'girl2'),
(7, 104, 'girl1'),
(8, 104, 'man1');
