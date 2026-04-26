<!DOCTYPE html>
<!-- saved from url=(0054)https://webcourse.ncue.edu.tw/Web/PHP/mid_bulletin.php -->
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title> 公告張貼 </title>
        <script src="https://code.jquery.com/jquery-3.7.1.min.js"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/jquery-validate/1.19.5/jquery.validate.min.js"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/jquery-validate/1.19.5/additional-methods.min.js"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/jquery-validate/1.19.5/localization/messages_zh_TW.min.js"></script>
        <link href="/post_style.css" rel="stylesheet" type="text/css" />
        <script>
            $(document).ready(function($){
                $("#form1").validate({
                    submitHandler: function(form) {
                        form.submit();
                    },
                    rules: {
                        to_1: {
                            require_from_group: [1, ".to_group"]
                        },
                        to_2: {
                            require_from_group: [1, ".to_group"]
                        },
                        to_3: {
                            require_from_group: [1, ".to_group"]
                        },
                        type: {
                            required: true
                        },
                        abstract: {
                            required: true
                        },
                        link: {
                            required: true,
                            url:true
                        },
                        content: {
                            required: true
                        },
                    },
                    messages: {
                        to_1: {
                            require_from_group: ""
                        },
                        to_2: {
                            require_from_group: ""
                        },
                        to_3: {
                            require_from_group: "請至少選擇1項"
                        }

                    }
                });
            });
        </script>
        <style type="text/css">
            .error {
                color: red;
                font-weight: normal;
            }
            table{
                margin:0 auto;
            border-collapse: collapse;
            }
            td {
                border: 1px solid #666;
                padding: 6px 8px;
            }
            .c_title {
                background: #f2f2f2;
                font-weight: 700;
            }
            .c_button {
                padding: 4px 10px;
                }
        </style>
    </head>

    <body>
        <form name="form1" id="form1" action="" method="POST" novalidate="novalidate">
            <table>
                <tbody>
                    <tr>
                        <td class="c_title" width="110">公告對象：</td>
                        <td class="c_content" width="420">
                            <label><input type="checkbox" class="to_group" name="to_1" <?= $to1 ? 'checked' : '' ?>>教職員</label>
                            <label><input type="checkbox" class="to_group" name="to_2" <?= $to2 ? 'checked' : '' ?>>學生</label>
                            <label><input type="checkbox" class="to_group" name="to_3" <?= $to3 ? 'checked' : '' ?>>學校首頁</label>
                            <span id="to_error"></span>
                        </td>
                    </tr>
                    <tr>
                        <td class="c_title">公告類型：</td>
                        <td class="c_content">
                            <label><input type="radio" name="type" value="1" <?= $type === '1' ? 'checked' : '' ?>>演講</label>
                            <label><input type="radio" name="type" value="2" <?= $type === '2' ? 'checked' : '' ?>>研討會</label>
                            <label><input type="radio" name="type" value="3" <?= $type === '3' ? 'checked' : '' ?>>徵才</label>
                            <label><input type="radio" name="type" value="4" <?= $type === '4' ? 'checked' : '' ?>>招生、進修教育訓練</label>
                            <label><input type="radio" name="type" value="5" <?= $type === '5' ? 'checked' : '' ?>> 其他</label>
                            <span id="type_error"></span>
                        </td>
                    </tr>
                    <tr>
                        <td class="c_title">主旨：</td>
                        <td class="c_content">
                            <input type="text" name="abstract" size="30" maxlength="30" value="<?= h($abstract) ?>">
                        </td>
                    </tr>
                    <tr>
                        <td class="c_title">公告截止日期：</td>
                        <td class="c_content">
                            <select name="year">
                                <?php for ($i = 101; $i <= 130; $i++): ?>
                                    <option value="<?= $i ?>" <?= $selectedYear === $i ? 'selected' : '' ?>><?= $i ?></option>
                                <?php endfor; ?>
                            </select>年
                            <select name="month">
                                <?php for ($i = 1; $i <= 12; $i++): ?>
                                    <option value="<?= $i ?>" <?= $selectedMonth === $i ? 'selected' : '' ?>><?= $i ?></option>
                                <?php endfor; ?>
                            </select>月
                            <select name="day">
                                <?php for ($i = 1; $i <= 31; $i++): ?>
                                    <option value="<?= $i ?>" <?= $selectedDay === $i ? 'selected' : '' ?>><?= $i ?></option>
                                <?php endfor; ?>
                            </select>日
                        </td>
                    </tr>
                    <tr>
                        <td class="c_title">連接網址：</td>
                        <td class="c_content">
                            <input type="text" name="link" size="20" value="<?= h($link) ?>">
                        </td>
                    </tr>
                    <tr>
                        <td class="c_title">公告內容：</td>
                        <td class="c_content">
                            <textarea name="content" rows="5" cols="40"><?= h($content) ?></textarea>
                        </td>
                    </tr>
                    <tr>
                        <td colspan="2" align="center">
                            <button type="submit" class="c_button">確定送出</button>
                            <button type="reset" class="c_button">重新填寫</button>
                        </td>
                    </tr>
                </tbody>
            </table>
        </form>

        <?php if ($isPost): ?>
            <?php
            $targets = [];
            if ($to1) {
                $targets[] = '教職員';
            }
            if ($to2) {
                $targets[] = '學生';
            }
            if ($to3) {
                $targets[] = '學校首頁';
            }
            ?>
            <table>
                <tbody>
                    <tr>
                        <td class="c_title" width="110">公告對象：</td>
                        <td class="c_content" width="420"><?= h(implode('、', $targets)) ?></td>
                    </tr>
                    <tr>
                        <td class="c_title">公告類型：</td>
                        <td class="c_content"><?= h($typeMap[$type] ?? '') ?></td>
                    </tr>
                    <tr>
                        <td class="c_title">主旨：</td>
                        <td class="c_content"><?= h($abstract) ?></td>
                    </tr>
                    <tr>
                        <td class="c_title">公告截止日期：</td>
                        <td class="c_content"><?= h($selectedYear) ?> 年 <?= h($selectedMonth) ?> 月 <?= h($selectedDay) ?> 日</td>
                    </tr>
                    <tr>
                        <td class="c_title">連接網址：</td>
                        <td class="c_content"><a href="<?= h($link) ?>" target="_blank"><?= h($link) ?></a></td>
                    </tr>
                    <tr>
                        <td class="c_title">公告內容：</td>
                        <td class="c_content"><?= nl2br(h($content)) ?></td>
                    </tr>
                </tbody>
            </table>
        <?php endif; ?>
    </body>
</html>