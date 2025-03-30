package com.shenby.readlandxml

import android.annotation.SuppressLint
import android.content.res.AssetManager
import androidx.appcompat.app.AppCompatActivity
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.withContext
import java.io.File
import java.io.FileOutputStream
import java.io.IOException
import java.io.InputStream


suspend fun AppCompatActivity.checkLandFile(folderName: String, fileName: String): File? {
    return withContext(Dispatchers.IO) {
        val folder = File(filesDir, folderName)
        if (!folder.exists()) {
            folder.mkdirs()
        }

        copyAssetsFolder(folder, folderName)

        val file = File(folder, fileName)
        if (file.exists() && file.isFile) {
            return@withContext file
        }
        null
    }
}

/**
 * 把assets的文件夹 复制到 targetFolder 文件夹，无需考虑权限的问题
 */
@SuppressLint("FileEndsWithExt")
suspend fun AppCompatActivity.copyAssetsFolder(targetFolder: File, assetsFolder: String): Boolean {
    return withContext(Dispatchers.IO) {
        val assetManager: AssetManager = assets
        return@withContext try {
            // 获取assets文件夹中的所有文件和子文件夹
            val files = assetManager.list(assetsFolder) ?: return@withContext false

            // 遍历每个文件/子文件夹
            for (file in files) {
                val assetPath = "$assetsFolder/$file"
                // 检查如果是文件夹则递归调用
                if (assetManager.list(assetPath).isNullOrEmpty()) {
                    // 复制文件
                    copyAssetFile(assetManager, assetPath, targetFolder.resolve(file))
                } else {
                    // 创建子文件夹
                    val subFolder = targetFolder.resolve(file)
                    subFolder.mkdirs()
                    // 递归调用
                    copyAssetsFolder(subFolder, assetPath)
                }
            }
            true
        } catch (e: IOException) {
            e.printStackTrace()
            false
        }
    }
}

/**
 * 复制单个文件
 */
fun copyAssetFile(assetManager: AssetManager, assetPath: String, outFile: File) {
    if (outFile.exists()) {
        return
    }
    assetManager.open(assetPath).use { inputStream: InputStream ->
        FileOutputStream(outFile).use { outputStream ->
            inputStream.copyTo(outputStream)
        }
    }
}
