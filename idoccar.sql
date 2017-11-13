-- phpMyAdmin SQL Dump
-- version 4.6.5.2
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Czas generowania: 13 Lis 2017, 20:41
-- Wersja serwera: 10.1.21-MariaDB
-- Wersja PHP: 5.6.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Baza danych: `idoccar`
--

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `cars`
--

CREATE TABLE `cars` (
  `ID` int(11) NOT NULL,
  `MARK` varchar(50) COLLATE utf8_polish_ci NOT NULL,
  `MODEL` varchar(50) COLLATE utf8_polish_ci NOT NULL,
  `PLATE` varchar(20) COLLATE utf8_polish_ci NOT NULL,
  `VIN` varchar(50) COLLATE utf8_polish_ci NOT NULL,
  `YEAR` date NOT NULL,
  `INSURANCE` date NOT NULL,
  `TANKS` int(1) NOT NULL,
  `TANK1` decimal(9,2) NOT NULL,
  `TANK2` decimal(9,2) NOT NULL,
  `MILAGE` int(11) NOT NULL,
  `USER` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_polish_ci ROW_FORMAT=COMPACT;

--
-- Zrzut danych tabeli `cars`
--

INSERT INTO `cars` (`ID`, `MARK`, `MODEL`, `PLATE`, `VIN`, `YEAR`, `INSURANCE`, `TANKS`, `TANK1`, `TANK2`, `MILAGE`, `USER`) VALUES
(1, 'Opel', 'Astra', 'WND 00001', 'W0L0AHL4878065000', '2007-10-21', '2018-03-21', 2, '52.00', '37.00', 137000, 1);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `costs`
--

CREATE TABLE `costs` (
  `ID` int(11) NOT NULL,
  `TITLE` varchar(50) COLLATE utf8_polish_ci NOT NULL,
  `DATE` date NOT NULL,
  `TYPE` int(3) NOT NULL,
  `NOTES` text COLLATE utf8_polish_ci NOT NULL,
  `MILAGE` int(11) NOT NULL,
  `COST` decimal(9,2) NOT NULL,
  `CARID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_polish_ci;

--
-- Zrzut danych tabeli `costs`
--

INSERT INTO `costs` (`ID`, `TITLE`, `DATE`, `TYPE`, `NOTES`, `MILAGE`, `COST`, `CARID`) VALUES
(1, 'Wymiana opon', '2017-09-20', 2, '', 100, '50.00', 1);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `costtypes`
--

CREATE TABLE `costtypes` (
  `ID` int(11) NOT NULL,
  `NAME` varchar(50) COLLATE utf8_polish_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_polish_ci ROW_FORMAT=COMPACT;

--
-- Zrzut danych tabeli `costtypes`
--

INSERT INTO `costtypes` (`ID`, `NAME`) VALUES
(2, 'Eksploatacja'),
(8, 'Inne'),
(6, 'Mandaty'),
(5, 'Myjnia'),
(4, 'Parking'),
(3, 'Rejestracja'),
(1, 'Serwis'),
(7, 'Ubezpieczenie');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `fuel`
--

CREATE TABLE `fuel` (
  `ID` int(11) NOT NULL,
  `DATE` date NOT NULL,
  `FUEL` decimal(9,2) NOT NULL,
  `PRICE` decimal(9,2) NOT NULL,
  `MILAGE` int(11) NOT NULL,
  `COMBUSTION` decimal(9,2) NOT NULL DEFAULT '0.00',
  `TANK` int(1) NOT NULL,
  `NOTES` text COLLATE utf8_polish_ci NOT NULL,
  `CARID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_polish_ci;

--
-- Zrzut danych tabeli `fuel`
--

INSERT INTO `fuel` (`ID`, `DATE`, `FUEL`, `PRICE`, `MILAGE`, `COMBUSTION`, `TANK`, `NOTES`, `CARID`) VALUES
(1, '2017-11-13', '52.00', '234.00', 400, '13.00', 1, 'Nie ma lipy', 1);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `users`
--

CREATE TABLE `users` (
  `ID` int(11) NOT NULL,
  `FIRST_NAME` varchar(50) COLLATE utf8_polish_ci NOT NULL,
  `LAST_NAME` varchar(50) COLLATE utf8_polish_ci NOT NULL,
  `LOGIN` varchar(50) COLLATE utf8_polish_ci NOT NULL,
  `PASS` varchar(50) COLLATE utf8_polish_ci NOT NULL,
  `EMAIL` varchar(100) COLLATE utf8_polish_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_polish_ci;

--
-- Zrzut danych tabeli `users`
--

INSERT INTO `users` (`ID`, `FIRST_NAME`, `LAST_NAME`, `LOGIN`, `PASS`, `EMAIL`) VALUES
(1, 'Łukasz', 'Wiśniewski', 'lwisnie', '1234', 'mail@gmail.com');

--
-- Indeksy dla zrzutów tabel
--

--
-- Indexes for table `cars`
--
ALTER TABLE `cars`
  ADD PRIMARY KEY (`ID`),
  ADD UNIQUE KEY `VIN` (`VIN`);

--
-- Indexes for table `costs`
--
ALTER TABLE `costs`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `costtypes`
--
ALTER TABLE `costtypes`
  ADD PRIMARY KEY (`ID`),
  ADD UNIQUE KEY `NAME` (`NAME`);

--
-- Indexes for table `fuel`
--
ALTER TABLE `fuel`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`ID`),
  ADD UNIQUE KEY `LOGIN` (`LOGIN`,`EMAIL`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT dla tabeli `cars`
--
ALTER TABLE `cars`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;
--
-- AUTO_INCREMENT dla tabeli `costs`
--
ALTER TABLE `costs`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;
--
-- AUTO_INCREMENT dla tabeli `costtypes`
--
ALTER TABLE `costtypes`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;
--
-- AUTO_INCREMENT dla tabeli `fuel`
--
ALTER TABLE `fuel`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;
--
-- AUTO_INCREMENT dla tabeli `users`
--
ALTER TABLE `users`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
