<?php
/*
 *  Robi the PHP robot
 *  A control and login interface
 *  Copyright (c) 2020 Maxim Verhoef
 *  contact@maximverhoef.nl
 */

session_start();
// Check of gebruiker (al) ingelogd is.
if (!isset($_SESSION["login"]) ) {
    header("Location: logout.php");
    exit;
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8"/>
    <meta http-equiv="X-UA-Compatible" content="IE=edge"/>
    <meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=0, minimal-ui">
    <title>Control - Robi the PHPRobot</title>
    <link href="assets/css/style.css" rel="stylesheet">
    <link rel="icon" href="">
</head>
<body>
<!-- Header -->
<header>
<div class="logo-container">
    <!-- Main logo -->
    <svg id="logo" data-name="logo" viewBox="0 0 1092 480">
        <path class="orange" d="M456,376H600a48,48,0,0,0,48-48V280H360V472h0a96,96,0,0,0,96-96Z" transform="translate(-360 -280)"/>
        <path class="red" d="M696,568a48,48,0,0,0,48-48V360H696a48,48,0,0,0-48,48v64H552a95.58,95.58,0,0,0-45.08,11.22,90.93,90.93,0,0,0-8,4.76,96,96,0,0,0-43,80h0L634.06,746a48,48,0,0,0,67.84-67.88L591.76,568H696Z" transform="translate(-360 -280)"/>
        <path class="red" d="M1247.66,280H1056c5,109.92,112.44,96.93,191.66,95.79v95.8H1103.91c-10.17,127.05,52.51,90.09,143.75,95.79v95.79h-95.83V615.28c-2.52-55-56.22-48.47-95.83-47.9V759h95.83c79.34,1.13,186.6,14.1,191.65-95.8V519.48a47.9,47.9,0,0,0-47.91-47.89c55-2.55,48.47-56.17,47.91-95.8A95.81,95.81,0,0,0,1247.66,280Z" transform="translate(-360 -280)"/>
        <path class="red" d="M852,471.91V663.83h0a96,96,0,0,0,96-96V376h0A96,96,0,0,0,852,471.91Z" transform="translate(-360 -280)"/>
        <path class="red" d="M948,280h0v96h96A96,96,0,0,0,948,280Z" transform="translate(-360 -280)"/>
        <path class="red" d="M756,663.83a96,96,0,0,0,96,95.95h0V663.83Z" transform="translate(-360 -280)"/>
        <path class="orange" d="M852,280.22a96,96,0,0,0-96,95.95v96h0a96,96,0,0,0,96-96V280.22Z" transform="translate(-360 -280)"/>
        <path class="orange" d="M1044,568a96,96,0,0,0-96,96v95.95h0A96,96,0,0,0,1044,664V568Z" transform="translate(-360 -280)"/>
        <path class="orange" d="M1356,496V760h0a96,96,0,0,0,96-96V400h0A96,96,0,0,0,1356,496Z" transform="translate(-360 -280)"/>
        <path class="red" d="M1356,280v96h0a96,96,0,0,0,96-96h-96Z" transform="translate(-360 -280)"/>
    </svg>
    <!-- Sub logo line-->
    <span class="logo-sub">The PHP Robot</span>
</div>
    <!-- Logout button -->
    <button class="btn-primary" onclick="location.href='logout.php'">Logout</button>
</header>
<!-- End of header -->
<!-- Main -->
<main>
    <!-- Remote control -->
    <div class="btn_grid">
        <!-- Row of button 1, 2 and 3 -->
        <div class="btn_grid-row">
        <button class="btn_grid-row--item" style="border-color: #732103;">Dans 1</button>
        <button class="btn_grid-row--item">Vooruit</button>
        <button class="btn_grid-row--item" style="border-color: #732103;">Dans 2</button>
        </div>
        <!-- Row of button 4, 5 and 6 -->
        <div class="btn_grid-row">
        <button class="btn_grid-row--item">Rechts</button>
        <button class="btn_grid-row--item" style="border-color: #732103;">Toeter</button>
        <button class="btn_grid-row--item">Links</button>
        </div>
        <!-- Row of button 7 -->
        <div class="btn_grid-row">
        <button class="btn_grid-row--item">Achteruit</button>
        </div>
    </div>
</main>
<!-- End of main -->
<!-- Footer -->
<footer>
    <!-- Disconnect button -->
    <button class="btn-primary">Disconnect</button>
    <!-- Connection indicator -->
    <div class="status_indicator">
        Websocket status
        <span class="status_indicator-status">Connected</span>
    </div>
</footer>
<!-- End of footer -->
</body>
</html>